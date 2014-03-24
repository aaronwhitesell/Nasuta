#include "button.h"

#include "../../Game/Resources/resourceIdentifiers.h"

#include "Trambo/Sounds/soundPlayer.h"
#include "Trambo/Utilities/utility.h"

#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Window/Event.hpp>


namespace GUI
{

Button::Button(trmb::State::Context context, int buttonWidth, int buttonHeight)
: mCallback()
, mSprite(context.textures->get(Textures::ID::Buttons))
, mText("", context.fonts->get(Fonts::ID::Main), 16)
, mIsToggle(false)
, mSounds(*context.sounds)
, mButtonWidth(buttonWidth)
, mButtonHeight(buttonHeight)
{
	changeTexture(Type::Normal);

	sf::FloatRect bounds = mSprite.getLocalBounds();
	mText.setPosition(bounds.width / 2.f, bounds.height / 2.f);
}

void Button::setCallback(Callback callback)
{
	mCallback = std::move(callback);
}

void Button::setText(const std::string& text)
{
	mText.setString(text);
	trmb::centerOrigin(mText);
}

void Button::setToggle(bool flag)
{
	mIsToggle = flag;
}

bool Button::isSelectable() const
{
	return true;
}

void Button::select()
{
	Component::select();

	changeTexture(Type::Selected);
}

void Button::deselect()
{
	Component::deselect();

	changeTexture(Type::Normal);
}

void Button::press()
{
	Component::press();

	changeTexture(Type::Pressed);
}

void Button::cancelPress()
{
	Component::cancelPress();

	changeTexture(Type::Selected);
}

void Button::activate()
{
	Component::cancelPress();
	Component::activate();

	if (mCallback)
		mCallback();

	// If we are not a toggle then deactivate the button since we are just momentarily activated.
	if (!mIsToggle)
		deactivate();

	mSounds.play(SoundEffects::ID::Button);
}

void Button::deactivate()
{
	Component::deactivate();

	// Reset texture to right one depending on if we are selected or not.
	if (isSelected())
		changeTexture(Type::Selected);
	else
		changeTexture(Type::Normal);
}

void Button::handleEvent(const sf::Event&)
{
}

void Button::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform *= getTransform();
	target.draw(mSprite, states);
	target.draw(mText, states);
}

void Button::changeTexture(Type buttonType)
{
	// ALW - This fcn relies on the assumption that all buttons are rectangular,
	// equal in size, and stacked vertically in the texture.
	const int buttonOffset = mButtonHeight;
	const sf::IntRect textureRect(0, buttonOffset * static_cast<int>(buttonType), mButtonWidth, mButtonHeight);
	mSprite.setTextureRect(textureRect);
}

bool Button::isIntersect(sf::Vector2i cursorPosition) const
{
	const sf::Vector2f buttonPosition = getPosition();

	return (cursorPosition.x > buttonPosition.x)
		&& (cursorPosition.x < buttonPosition.x + mButtonWidth)
		&& (cursorPosition.y > buttonPosition.y)
		&& (cursorPosition.y < buttonPosition.y + mButtonHeight);
}

}
