/* Copyright 2014 CyberTech Labs Ltd.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License. */

#pragma once

#include <QtCore/qglobal.h>

#if QT_VERSION < QT_VERSION_CHECK(5, 0, 0)
	#include <QtGui/QWidget>
#else
	#include <QtWidgets/QWidget>
#endif

#include "mainWidget.h"

namespace trikKernel {

/// Abstract class for widgets which will be used for conversation with user (but when it doesn't want to be shown immediately).
class LazyMainWidget : public MainWidget
{
	Q_OBJECT

public:
	LazyMainWidget(QWidget *parent = 0) : MainWidget (parent) {}
	virtual ~LazyMainWidget() {}

signals:
	void showMe(trikKernel::MainWidget &widget);
	void hideMe(trikKernel::MainWidget &widget);
	void abortMe(trikKernel::MainWidget &widget);
};
}

