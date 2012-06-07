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

#include "GOGUIControl.h"
#include "GOGUIPanel.h"
#include "GOrgueConfigReader.h"

GOGUIControl::GOGUIControl(GOGUIPanel* panel,void* control) :
	m_panel(panel),
	m_group(wxT("---")),
	m_control(control),
	m_BoundingRect(0, 0, 0, 0),
	m_DrawPending(false)
{
	m_metrics = panel->GetDisplayMetrics();
}

GOGUIControl::~GOGUIControl()
{
}

void GOGUIControl::Load(GOrgueConfigReader& cfg, wxString group)
{
	m_group = group;
}

void GOGUIControl::Save(GOrgueConfigWriter& cfg)
{
}

void GOGUIControl::ControlChanged(void* control)
{
	if (control == m_control)
		if (!m_DrawPending)
		{
			m_DrawPending = true;
			m_panel->AddEvent(this);
		}
}

void GOGUIControl::Draw(wxDC* dc)
{
	m_DrawPending = false;
}

void GOGUIControl::HandleKey(int key)
{
}

void GOGUIControl::HandleMousePress(int x, int y, bool right, GOGUIMouseState& state)
{
}

void GOGUIControl::HandleMouseScroll(int x, int y, int amount)
{
}

const wxRect& GOGUIControl::GetBoundingRect()
{
	return m_BoundingRect;
}
