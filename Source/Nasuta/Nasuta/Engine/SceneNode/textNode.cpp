#include "textNode.h"

#include "../../Game/Resources/resourceIdentifiers.h"

#include "Trambo/Utilities/utility.h"

#include <SFML/Graphics/RenderTarget.hpp>


TextNode::TextNode(const trmb::FontHolder& fonts, const std::string& text)
{
	mText.setFont(fonts.get(Fonts::ID::Main));
	mText.setCharacterSize(20);
	setString(text);
}

void TextNode::setString(const std::string& text)
{
	mText.setString(text);
	trmb::centerOrigin(mText);
}

void TextNode::drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(mText, states);
}
