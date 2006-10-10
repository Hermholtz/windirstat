// layout.h - Declaration of CLayout
//
// WinDirStat - Directory Statistics
// Copyright (C) 2003-2005 Bernhard Seifert
// Copyright (C) 2004-2006 Oliver Schneider (assarbad.net)
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
//
// Author(s): - bseifert -> bseifert@users.sourceforge.net, bseifert@daccord.net
//            - assarbad -> http://assarbad.net/en/contact
//
// $Id$

#pragma once

//
// CLayout. A poor men's dialog layout mechanism.
// Simple, flat, and sufficient for our purposes.
//
class CLayout
{
	struct SControlInfo
	{
		CWnd *control;
		double movex;
		double movey;
		double stretchx;
		double stretchy;

		CRect originalRectangle;
	};

	class CSizeGripper: public CWnd
	{
	public:
		static const int _width;

		CSizeGripper();
		void Create(CWnd *parent, CRect rc);

	private:
		void DrawShadowLine(CDC *pdc, CPoint start, CPoint end);

		DECLARE_MESSAGE_MAP()
		afx_msg void OnPaint();
		afx_msg LRESULT OnNcHitTest(CPoint point);
	};

	class CPositioner  
	{
	public:
		CPositioner(int nNumWindows = 10);
		virtual ~CPositioner();
		void SetWindowPos(HWND hWnd, int x, int y, int cx, int cy, UINT uFlags);
	private:
		HDWP m_wdp;
	};

public:
	CLayout(CWnd *dialog, LPCTSTR name);
	int AddControl(CWnd *control, double movex, double movey, double stretchx, double stretchy);
	void AddControl(UINT id, double movex, double movey, double stretchx, double stretchy);

	void OnInitDialog(bool centerWindow);
	void OnSize();
	void OnGetMinMaxInfo(MINMAXINFO *mmi);
	void OnDestroy();

protected:
	CWnd *m_dialog;
	CString m_name;
	CSize m_originalDialogSize;
	CArray<SControlInfo, SControlInfo&> m_control;
	CSizeGripper m_sizeGripper;
};

// $Log$
// Revision 1.8  2006/10/10 01:41:50  assarbad
// - Added credits for Gerben Wieringa (Dutch translation)
// - Replaced Header tag by Id for the CVS tags in the source files ...
// - Started re-ordering of the files inside the project(s)/solution(s)
//
// Revision 1.7  2006/07/04 23:37:39  assarbad
// - Added my email address in the header, adjusted "Author" -> "Author(s)"
// - Added CVS Log keyword to those files not having it
// - Added the files which I forgot during last commit
//
// Revision 1.6  2006/07/04 22:49:20  assarbad
// - Replaced CVS keyword "Date" by "Header" in the file headers
//
// Revision 1.5  2006/07/04 20:45:23  assarbad
// - See changelog for the changes of todays previous check-ins as well as this one!
//
// Revision 1.4  2004/11/05 16:53:07  assarbad
// Added Date and History tag where appropriate.
//
