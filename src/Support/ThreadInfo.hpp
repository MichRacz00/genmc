/*
 * GenMC -- Generic Model Checking.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, you can access it online at
 * http://www.gnu.org/licenses/gpl-3.0.html.
 *
 * Author: Michalis Kokologiannakis <michalis@mpi-sws.org>
 */

#ifndef GENMC_THREAD_INFO_HPP
#define GENMC_THREAD_INFO_HPP

#include "SVal.hpp"
#include "config.h"

struct ThreadInfo {
	int id;
	int parentId;
	unsigned int funId;
	SVal arg;
	int symmId = -1;

	ThreadInfo() = default;
	ThreadInfo(int id, int parentId, unsigned funId, SVal arg, int symm = -1)
		: id(id), parentId(parentId), funId(funId), arg(arg), symmId(symm)
	{}
};

#endif /* GENMC_THREAD_INFO_HPP */