/*! **************************************************************************
 *   Screenhot - Simple screenshot application for Qt QML
 *   Copyright (C) 2025  P.ColdBrew     (AU)
 *                       2025-10-01
 *                       projectcoldbrew@gmail.com
 *
 *   This program is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program.  If not, see <https://www.gnu.org/licenses/>.
 ****************************************************************************/
#include <QApplication>
#include <QQmlApplicationEngine>

#include "screenshotclass.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    // Register the class, this can be done here or in a user created plugin:
    qmlRegisterType<ScreenshotClass>("Utils", 1, 0, "ScreenshotUtil");

    QQmlApplicationEngine engine;
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.loadFromModule("Screenshot", "Main");

    return app.exec();
}
