
// HelloWorldView.h : interface of the CHelloWorldView class
//

#pragma once


class CHelloWorldView : public CView
{
protected: // create from serialization only
	CHelloWorldView() noexcept;
	DECLARE_DYNCREATE(CHelloWorldView)

// Attributes
public:
	CHelloWorldDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CHelloWorldView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnDrawCircle();

private:
	bool m_drawCircle{ true }; // if not circle then a rectangle
public:
	afx_msg void OnDrawRectangle();
	afx_msg void OnUpdateDrawCircle(CCmdUI* pCmdUI);
	afx_msg void OnUpdateDrawRectangle(CCmdUI* pCmdUI);
};

#ifndef _DEBUG  // debug version in HelloWorldView.cpp
inline CHelloWorldDoc* CHelloWorldView::GetDocument() const
   { return reinterpret_cast<CHelloWorldDoc*>(m_pDocument); }
#endif

