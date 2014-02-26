#include "particleNode.h"
#include "../Resource/resourceHolder.h"

#include "../../../../3rdParty/TinyXML2/tinyxml2.h"

#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Texture.hpp>

#include <algorithm>


ParticleNode::ParticleNode(Particle::Type type, const TextureHolder& textures)
: SceneNode()
, mParticles()
, mTexture(textures.get(Textures::Particle))
, mType(type)
, mVertexArray(sf::Quads)
, mNeedsVertexUpdate(true)
{
	readXML(mType);
}

void ParticleNode::addParticle(sf::Vector2f position)
{
	Particle particle;
	particle.position = position;
	particle.color = mData.color;
	particle.lifetime = mData.lifetime;

	mParticles.push_back(particle);
}

Particle::Type ParticleNode::getParticleType() const
{
	return mType;
}

unsigned int ParticleNode::getCategory() const
{
	return Category::ParticleSystem;
}

void ParticleNode::updateCurrent(sf::Time dt, CommandQueue&)
{
	// Remove expired particles at beginning
	while (!mParticles.empty() && mParticles.front().lifetime <= sf::Time::Zero)
		mParticles.pop_front();

	// Decrease lifetime of existing particles
	for (Particle& particle : mParticles)
		particle.lifetime -= dt;

	mNeedsVertexUpdate = true;
}

void ParticleNode::drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const
{
	if (mNeedsVertexUpdate)
	{
		computeVertices();
		mNeedsVertexUpdate = false;
	}

	// Apply particle texture
	states.texture = &mTexture;

	// Draw vertices
	target.draw(mVertexArray, states);
}

void ParticleNode::addVertex(float worldX, float worldY, float texCoordX, float texCoordY, const sf::Color& color) const
{
	sf::Vertex vertex;
	vertex.position = sf::Vector2f(worldX, worldY);
	vertex.texCoords = sf::Vector2f(texCoordX, texCoordY);
	vertex.color = color;

	mVertexArray.append(vertex);
}

void ParticleNode::computeVertices() const
{
	sf::Vector2f size(mTexture.getSize());
	sf::Vector2f half = size / 2.f;

	// Refill vertex array
	mVertexArray.clear();
	for (const Particle& particle : mParticles)
	{
		sf::Vector2f pos = particle.position;
		sf::Color color = particle.color;

		float ratio = particle.lifetime.asSeconds() / mData.lifetime.asSeconds();
		color.a = static_cast<sf::Uint8>(255 * std::max(ratio, 0.f));

		addVertex(pos.x - half.x, pos.y - half.y, 0.f,    0.f,    color);
		addVertex(pos.x + half.x, pos.y - half.y, size.x, 0.f,    color);
		addVertex(pos.x + half.x, pos.y + half.y, size.x, size.y, color);
		addVertex(pos.x - half.x, pos.y + half.y, 0.f,    size.y, color);
	}
}

std::string ParticleNode::toString(Particle::Type type) const
{
	std::string ret;
	switch (type)
	{
		case 0:
			ret = "Propellant";
			break;

		case 1:
			ret = "Smoke";
			break;
	}

	// ALW - Will assert if type does not correspond to a string
	assert(ret.compare("") != 0);
	return ret;
}

void ParticleNode::readXML(Particle::Type type)
{
	const std::string filename("Data/Configs/Particles.xml");
	tinyxml2::XMLDocument config;
	if (config.LoadFile(filename.c_str()) != tinyxml2::XML_NO_ERROR)
	{
		throw std::runtime_error("TinyXML2 - Failed to load " + filename);
	}

	const tinyxml2::XMLElement* element = config.FirstChildElement()->FirstChildElement(toString(type).c_str());
	if (!element)
	{
		// ALW - Will assert if the type's element does not exist
		assert(element);
	}

	mData.lifetime         = sf::seconds(element->FirstChildElement("lifetime")->FloatAttribute("attribute"));

	const int red          = element->FirstChildElement("color")->IntAttribute("attribute0");
	const int green        = element->FirstChildElement("color")->IntAttribute("attribute1");
	const int blue         = element->FirstChildElement("color")->IntAttribute("attribute2");
	mData.color            = sf::Color(red, green, blue);
}