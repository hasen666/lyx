// -*- C++ -*-
/**
 * \file GuiProgress.h
 * This file is part of LyX, the document processor.
 * Licence details can be found in the file COPYING.
 *
 * \author Peter Kümmel
 *
 * Full author contact details are available in file CREDITS.
 */

#ifndef GUIPROGRESS_H
#define GUIPROGRESS_H

#include "support/ProgressInterface.h"

#include "DockView.h"

#include <QTextEdit>
#include <QSplashScreen>
#include <QTimer>

#include <string>


namespace lyx {
namespace frontend {


class GuiProgress :
		public QObject,
		public lyx::support::ProgressInterface
{
	Q_OBJECT

public:
	GuiProgress(GuiView * view);


Q_SIGNALS:
	void processStarted(QString const &);
	void processFinished(QString const &);
	void appendMessage(QString const &);
	void appendError(QString const &);
	void clearMessages();

	// Alert interface
	void warning(QString const & title, QString const & message);
	void toggleWarning(QString const & title, QString const & msg, QString const & formatted);
	void error(QString const & title, QString const & message);
	void information(QString const & title, QString const & message);

private Q_SLOTS:
	void doProcessStarted(QString const &);
	void doProcessFinished(QString const &);
	void doAppendMessage(QString const &);
	void doAppendError(QString const &);
	void doClearMessages();


	void doWarning(QString const &, QString const &);
	void doToggleWarning(QString const & title, QString const & msg, QString const & formatted);
	void doError(QString const &, QString const &);
	void doInformation(QString const &, QString const &);


private:
	GuiView* view_;
	void appendText(QString const &);

};



} // namespace frontend
} // namespace lyx

#endif
