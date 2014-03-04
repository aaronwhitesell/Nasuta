#include "button.h"
#include "../utility.h"
#include "../Resource/resourceHolder.h"
#include "../Sound/soundPlayer.h"

#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Window/Event.hpp>


namespace GUI
{

Button::Button(State::Context context)
: mCallback()
, mSprite(context.textures->get(Textures::Buttons))
, mText("", context.fonts->get(Fonts::Main), 16)
, mIsToggle(false)
, mSounds(*context.sounds)
{
	changeTexture(Normal);

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
	centerOrigin(mText);
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

	changeTexture(Selected);
}

void Button::deselect()
{
	Component::deselect();

	changeTexture(Normal);
}

void Button::press()
{
	Component::press();

	changeTexture(Pressed);
}

void Button::cancelPress()
{
	Component::cancelPress();

	changeTexture(Selected);
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

	mSounds.play(SoundEffect::Button);
}

void Button::deactivate()
{
	Component::deactivate();

	// Reset texture to right one depending on if we are selected or not.
	if (isSelected())
		changeTexture(Selected);
	else
		changeTexture(Normal);
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
	sf::IntRect textureRect(0, 50*buttonType, 200, 50);
	mSprite.setTextureRect(textureRect);
}

bool Button::isIntersect(sf::Vector2i cursorPosition) const
{
	// ALW - TODO: Button width and height are hardcoded
	const int width = 200;
	const int height = 50;
	const sf::Vector2f buttonPosition = getPosition();

	return (cursorPosition.x > buttonPosition.x) && (cursorPosition.x < buttonPosition.x + width)
			&& (cursorPosition.y > buttonPosition.y) && (cursorPosition.y < buttonPosition.y + height);
}

}
