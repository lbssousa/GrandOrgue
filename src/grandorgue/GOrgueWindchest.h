/*
 * GrandOrgue - free pipe organ simulator
 *
 * Copyright 2006 Milan Digital Audio LLC
 * Copyright 2009-2012 GrandOrgue contributors (see AUTHORS)
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of the
 * License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#ifndef GORGUEWINDCHEST_H
#define GORGUEWINDCHEST_H

#include <vector>
#include <wx/wx.h>

class GOrgueConfigReader;
class GOrgueRank;
class GOrguePipe;
class GrandOrgueFile;

class GOrgueWindchest
{
private:
	GrandOrgueFile* m_organfile;
	wxString m_Name;
	std::vector<unsigned> m_enclosure;
	std::vector<unsigned> m_tremulant;
	std::vector<GOrgueRank*> m_ranks;
	std::vector<GOrguePipe*> m_pipes;

public:

	GOrgueWindchest(GrandOrgueFile* organfile);
	void Load(GOrgueConfigReader& cfg, wxString group, unsigned index);
	void ControlChanged(void* control);
	float GetVolume();
	unsigned GetTremulantCount();
	unsigned GetTremulantId(unsigned index);
	unsigned GetRankCount();
	GOrgueRank* GetRank(unsigned index);
	void AddRank(GOrgueRank* rank);
	void AddPipe(GOrguePipe* pipe);
	const wxString& GetName();
};

#endif /* GORGUEWINDCHEST_H_ */
