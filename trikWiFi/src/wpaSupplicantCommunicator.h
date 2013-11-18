/* Copyright 2013 Roman Kurbatov, Yurii Litvinov
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License. */

#pragma once

#include <QtCore/QObject>
#include <QtCore/QScopedPointer>

#include "declSpec.h"

struct sockaddr_un;

namespace trikWiFi {

/// Allows communication with wpa_supplicant daemon.
class TRIKWIFI_EXPORT WpaSupplicantCommunicator : public QObject
{
	Q_OBJECT

public:
	WpaSupplicantCommunicator(QString const &interfaceFile, QString const &daemonFile, QObject *parent = 0);
	~WpaSupplicantCommunicator();
	int fileDescriptor();
	int attach();
	int detach();
	int request(QString const &command, QString &reply);
	bool isPending();
	int receive(QString &message);

private:
	int mSocket;
	QScopedPointer<sockaddr_un> mLocal;
	QScopedPointer<sockaddr_un> mDest;
};

}