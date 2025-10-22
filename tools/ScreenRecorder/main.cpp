/*! **************************************************************************
 *   ScreenRecorder - Simple screen recording application for Qt QML
 *   Copyright (C) 2025  P.ColdBrew     (AU)
 *                       2025-10-22
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
#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "recorder.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    qmlRegisterType<Recorder>("Utils", 1, 0, "MyRecorder");

    QQmlApplicationEngine engine;
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.loadFromModule("ScreenRecorder", "Main");

    return app.exec();
}
