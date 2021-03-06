/* Copyright 2015 CyberTech Labs Ltd.
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

#include "gamepadFactory.h"

#include <trikKernel/configurer.h>

#include "gamepad.h"

using namespace trikNetwork;

GamepadInterface *GamepadFactory::create(int port)
{
	return new Gamepad(port);
}

GamepadInterface *GamepadFactory::create(const trikKernel::Configurer &configurer)
{
	if (configurer.isEnabled("gamepad")) {
		return new Gamepad(configurer);
	} else {
		return nullptr;
	}
}
