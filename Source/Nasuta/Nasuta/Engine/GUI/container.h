#ifndef CONTAINER_H
#define CONTAINER_H

#include "component.h"

#include <SFML/Graphics/RenderWindow.hpp>

#include <memory>
#include <vector>


namespace sf
{
	class RenderWindow;
}

namespace GUI
{

class Container : public Component
{
public:
	typedef std::shared_ptr<Container> Ptr;


public:
						Container();
	explicit			Container(sf::RenderWindow* window);

	void				pack(Component::Ptr component);

	virtual bool		isSelectable() const;
	virtual void		handleEvent(const sf::Event& event);


private:
	virtual void		draw(sf::RenderTarget& target, sf::RenderStates states) const;

	bool				hasSelection() const;
	void				select(std::size_t index);
	void				selectNext();
	void				selectPrevious();


private:
	std::vector<Component::Ptr>		mChildren;
	int								mSelectedChild;
	sf::RenderWindow*				mWindow;
};

}

#endif
