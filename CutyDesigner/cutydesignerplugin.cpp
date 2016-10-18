#include "cutydesigner.h"

#include <QtCore/QtPlugin>
#include "cutydesignerplugin.h"


CutyDesignerPlugin::CutyDesignerPlugin(QObject *parent)
	: QObject(parent)
{
	initialized = false;
}

void CutyDesignerPlugin::initialize(QDesignerFormEditorInterface * /*core*/)
{
	if (initialized)
		return;

	initialized = true;
}

bool CutyDesignerPlugin::isInitialized() const
{
	return initialized;
}

QWidget *CutyDesignerPlugin::createWidget(QWidget *parent)
{
	return new CutyDesigner(parent);
}

QString CutyDesignerPlugin::name() const
{
	return "CutyDesigner";
}

QString CutyDesignerPlugin::group() const
{
	return "My Plugins";
}

QIcon CutyDesignerPlugin::icon() const
{
	return QIcon();
}

QString CutyDesignerPlugin::toolTip() const
{
	return QString();
}

QString CutyDesignerPlugin::whatsThis() const
{
	return QString();
}

bool CutyDesignerPlugin::isContainer() const
{
	return false;
}

QString CutyDesignerPlugin::domXml() const
{
	return "<widget class=\"CutyDesigner\" name=\"cutyDesigner\">\n"
		" <property name=\"geometry\">\n"
		"  <rect>\n"
		"   <x>0</x>\n"
		"   <y>0</y>\n"
		"   <width>100</width>\n"
		"   <height>100</height>\n"
		"  </rect>\n"
		" </property>\n"
		"</widget>\n";
}

QString CutyDesignerPlugin::includeFile() const
{
	return "cutydesigner.h";
}

