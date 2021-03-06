/*
 * Copyright 2010-2012 OpenXcom Developers.
 *
 * This file is part of OpenXcom.
 *
 * OpenXcom is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * OpenXcom is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with OpenXcom.  If not, see <http://www.gnu.org/licenses/>.
 */
#include "RuleSoldier.h"

namespace OpenXcom
{

/**
 * Creates a blank ruleunit for a certain
 * type of soldier.
 * @param type String defining the type.
 */
RuleSoldier::RuleSoldier(const std::string &type) : _type(type), _minStats(), _maxStats(), _armor(""), _standHeight(0), _kneelHeight(0), _loftemps(0)
{

}

/**
 *
 */
RuleSoldier::~RuleSoldier()
{

}

/**
 * Loads the unit from a YAML file.
 * @param node YAML node.
 */
void RuleSoldier::load(const YAML::Node &node)
{
	for (YAML::Iterator i = node.begin(); i != node.end(); ++i)
	{
		std::string key;
		i.first() >> key;
		if (key == "type")
		{
			i.second() >> _type;
		}
		else if (key == "minStats")
		{
			i.second() >> _minStats;
		}
		else if (key == "maxStats")
		{
			i.second() >> _maxStats;
		}
		else if (key == "armor")
		{
			i.second() >> _armor;
		}
		else if (key == "standHeight")
		{
			i.second() >> _standHeight;
		}
		else if (key == "kneelHeight")
		{
			i.second() >> _kneelHeight;
		}
		else if (key == "loftemps")
		{
			i.second() >> _loftemps;
		}
	}
}

/**
 * Saves the unit to a YAML file.
 * @param out YAML emitter.
 */
void RuleSoldier::save(YAML::Emitter &out) const
{

	out << YAML::BeginMap;
	out << YAML::Key << "type" << YAML::Value << _type;
	out << YAML::Key << "minStats" << YAML::Value << _minStats;
	out << YAML::Key << "maxStats" << YAML::Value << _maxStats;
	out << YAML::Key << "armor" << YAML::Value << _armor;
	out << YAML::Key << "standHeight" << YAML::Value << _standHeight;
	out << YAML::Key << "kneelHeight" << YAML::Value << _kneelHeight;
	out << YAML::Key << "loftemps" << YAML::Value << _loftemps;
	out << YAML::EndMap;
}

/**
 * Returns the language string that names
 * this unit. Each unit type has a unique name.
 * @return Unit name.
 */
std::string RuleSoldier::getType() const
{
	return _type;
}

void RuleSoldier::setStats(struct UnitStats minStats, struct UnitStats maxStats)
{
	_minStats = minStats;
	_maxStats = maxStats;
}


void RuleSoldier::setArmor(const std::string &armor)
{
	_armor = armor;
}

void RuleSoldier::setVoxelParameters(int standHeight, int kneelHeight, int loftemps)
{
	_standHeight = standHeight;
	_kneelHeight = kneelHeight;
	_loftemps = loftemps;
}

UnitStats RuleSoldier::getMinStats() const
{
	return _minStats;
}
///
UnitStats RuleSoldier::getMaxStats() const
{
	return _maxStats;
}
///
int RuleSoldier::getStandHeight() const
{
	return _standHeight;
}
///
int RuleSoldier::getKneelHeight() const
{
	return _kneelHeight;
}
///
int RuleSoldier::getLoftemps() const
{
	return _loftemps;
}

std::string RuleSoldier::getArmor() const
{
	return _armor;
}

}
