/*
 * This file is part of the PulseView project.
 *
 * Copyright (C) 2012 Joel Holdsworth <joel@airwebreathe.org.uk>
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
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301 USA
 */

#ifndef PULSEVIEW_PV_DATA_LOGIC_H
#define PULSEVIEW_PV_DATA_LOGIC_H

#include "signaldata.h"

#include <deque>
#include <memory>

namespace pv {
namespace data {

class LogicSnapshot;

class Logic : public SignalData
{
public:
	Logic(unsigned int num_probes);

	int get_num_probes() const;

	void push_snapshot(
		std::shared_ptr<LogicSnapshot> &snapshot);

	std::deque< std::shared_ptr<LogicSnapshot> >&
		get_snapshots();

	void clear();

	uint64_t get_max_sample_count() const;

private:
	const unsigned int _num_probes;
	std::deque< std::shared_ptr<LogicSnapshot> > _snapshots;
};

} // namespace data
} // namespace pv

#endif // PULSEVIEW_PV_DATA_LOGIC_H
