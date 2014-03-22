#ifndef BUTTON_H
#define BUTTON_H

#include "component.h"

#include "Trambo/States/state.h"

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>

#include <functional>
#include <memory>
#include <string>
#include <vector>


namespace GUI
{

class Button : public Component
{
public:
	typedef std::shared_ptr<Button>		Ptr;
	typedef std::function<void()>		Callback;

	enum class Type
	{
		Normal,
		Selected,
		Pressed,
		ButtonCount
	};

public:
							Button(trmb::State::Context context, int buttonWidth, int buttonHeight);
								
	void					setCallback(Callback callback);
	void					setText(const std::string& text);
	void					setToggle(bool flag);

	virtual bool			isSelectable() const;

	virtual void			select();
	virtual void			deselect();
    virtual void            press();
    virtual void            cancelPress();
	virtual void			activate();
	virtual void			deactivate();

	virtual bool			isIntersect(sf::Vector2i cursorPosition) const;
	virtual void			handleEvent(const sf::Event& event);


private:
	virtual void			draw(sf::RenderTarget& target, sf::RenderStates states) const;
	void					changeTexture(Type buttonType);

private:
	Callback				mCallback;
	sf::Sprite				mSprite;
	sf::Text				mText;
	bool					mIsToggle;			// The button remains pressed (active) until explicitly changed (supports poll method).
	SoundPlayer&			mSounds;
	int                     mButtonWidth;
	int                     mButtonHeight;
};

}

#endif
