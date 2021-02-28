
// HelloWorldView.cpp : implementation of the CHelloWorldView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "HelloWorld.h"
#endif

#include "HelloWorldDoc.h"
#include "HelloWorldView.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CHelloWorldView

IMPLEMENT_DYNCREATE(CHelloWorldView, CView)

BEGIN_MESSAGE_MAP(CHelloWorldView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CHelloWorldView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONDOWN()
	ON_COMMAND(ID_DRAW_CIRCLE, &CHelloWorldView::OnDrawCircle)
	ON_COMMAND(ID_DRAW_RECTANGLE, &CHelloWorldView::OnDrawRectangle)
	ON_UPDATE_COMMAND_UI(ID_DRAW_CIRCLE, &CHelloWorldView::OnUpdateDrawCircle)
	ON_UPDATE_COMMAND_UI(ID_DRAW_RECTANGLE, &CHelloWorldView::OnUpdateDrawRectangle)
END_MESSAGE_MAP()

// CHelloWorldView construction/destruction

CHelloWorldView::CHelloWorldView() noexcept
{
	// TODO: add construction code here

}

CHelloWorldView::~CHelloWorldView()
{
}

BOOL CHelloWorldView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CHelloWorldView drawing

void CHelloWorldView::OnDraw(CDC* pDC)
{
	CHelloWorldDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
	// all drawing command actions here
	//pDC->TextOutW(200, 200, _T("Test String in View"));
	if (m_drawCircle)
		pDC->Ellipse(200, 200, 400, 400);
	else
		pDC->Rectangle(100, 100, 400, 400);

	pDC->TextOutW(100, 400, pDoc->GetText());
}


// CHelloWorldView printing


void CHelloWorldView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CHelloWorldView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CHelloWorldView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CHelloWorldView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CHelloWorldView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CHelloWorldView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CHelloWorldView diagnostics

#ifdef _DEBUG
void CHelloWorldView::AssertValid() const
{
	CView::AssertValid();
}

void CHelloWorldView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CHelloWorldDoc* CHelloWorldView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CHelloWorldDoc)));
	return (CHelloWorldDoc*)m_pDocument;
}
#endif //_DEBUG


// CHelloWorldView message handlers


void CHelloWorldView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	AfxMessageBox(_T("You Clicked the View Area"));
	CView::OnLButtonDown(nFlags, point);
}


void CHelloWorldView::OnDrawCircle()
{
	// TODO: Add your command handler code here
	m_drawCircle = true;
	Invalidate();
	UpdateWindow();
}


void CHelloWorldView::OnDrawRectangle()
{
	// TODO: Add your command handler code here
	m_drawCircle = false;
	Invalidate();
	UpdateWindow();
}


void CHelloWorldView::OnUpdateDrawCircle(CCmdUI* pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(!m_drawCircle);
}


void CHelloWorldView::OnUpdateDrawRectangle(CCmdUI* pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(m_drawCircle);
}
