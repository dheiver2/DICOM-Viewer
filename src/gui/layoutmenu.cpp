#include "layoutmenu.h"
#include "gui.h"

asclepios::gui::LayoutMenu::LayoutMenu(QWidget* parent)
	: QMenu(parent)
{
	initView();
	createConnections(parent->parentWidget());
}

//-----------------------------------------------------------------------------
void asclepios::gui::LayoutMenu::initView()
{
	m_ui.setupUi(this);
}

//-----------------------------------------------------------------------------
void asclepios::gui::LayoutMenu::createConnections(QWidget* parent) const
{
	Q_UNUSED(connect(this, &QMenu::triggered,
		this, &LayoutMenu::onActionTriggered));
	auto* const receiver = dynamic_cast<GUI*>(parent);
	Q_UNUSED(connect(this, &LayoutMenu::changeLayout,
		receiver, &GUI::onChangeLayout));
}

//-----------------------------------------------------------------------------s
void asclepios::gui::LayoutMenu::onActionTriggered(QAction* t_action)
{
	QApplication::setOverrideCursor(Qt::WaitCursor);
	const auto action = t_action->objectName();
	if (action == "actionOne")
	{
		emit changeLayout(WidgetsContainer::layouts::one);
	}
	else if (action == "actionTwoInRowOneBottom")
	{
		emit changeLayout(WidgetsContainer::layouts::twoRowOneBottom);
	}
	else if (action == "actionTwoInColumnOneRight")
	{
		emit changeLayout(WidgetsContainer::layouts::twoColumnOneRight);
	}
	else if (action == "actionThreeInRowOneBottom")
	{
		emit changeLayout(WidgetsContainer::layouts::threeRowOneBottom);
	}
	else if (action == "actionThreeInColumnOneRight")
	{
		emit changeLayout(WidgetsContainer::layouts::threeColumnOneRight);
	}
}
