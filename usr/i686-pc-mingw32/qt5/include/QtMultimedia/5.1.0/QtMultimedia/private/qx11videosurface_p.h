/****************************************************************************
**
** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies).
** Contact: http://www.qt-project.org/legal
**
** This file is part of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and Digia.  For licensing terms and
** conditions see http://qt.digia.com/licensing.  For further information
** use the contact form at http://qt.digia.com/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU Lesser General Public License version 2.1 requirements
** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Digia gives you certain additional
** rights.  These rights are described in the Digia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3.0 as published by the Free Software
** Foundation and appearing in the file LICENSE.GPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU General Public License version 3.0 requirements will be
** met: http://www.gnu.org/copyleft/gpl.html.
**
**
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef QX11VIDEOSURFACE_H
#define QX11VIDEOSURFACE_H

#include <QtWidgets/qwidget.h>
#include <qabstractvideosurface.h>

#include <X11/Xlib.h>
#include <X11/extensions/Xv.h>
#include <X11/extensions/Xvlib.h>

QT_BEGIN_NAMESPACE

class QX11VideoSurface : public QAbstractVideoSurface
{
    Q_OBJECT
public:
    QX11VideoSurface(QObject *parent = 0);
    ~QX11VideoSurface();

    WId winId() const;
    void setWinId(WId id);

    QRect displayRect() const;
    void setDisplayRect(const QRect &rect);

    QRect viewport() const;
    void setViewport(const QRect &rect);

    int brightness() const;
    void setBrightness(int brightness);

    int contrast() const;
    void setContrast(int contrast);

    int hue() const;
    void setHue(int hue);

    int saturation() const;
    void setSaturation(int saturation);

    QList<QVideoFrame::PixelFormat> supportedPixelFormats(
            QAbstractVideoBuffer::HandleType handleType = QAbstractVideoBuffer::NoHandle) const;

    bool start(const QVideoSurfaceFormat &format);
    void stop();

    bool present(const QVideoFrame &frame);

private:
    Display *display() const;

    WId m_winId;
    XvPortID m_portId;
    GC m_gc;
    XvImage *m_image;
    QList<QVideoFrame::PixelFormat> m_supportedPixelFormats;
    QVector<int> m_formatIds;
    QRect m_viewport;
    QRect m_displayRect;
    QPair<int, int> m_brightnessRange;
    QPair<int, int> m_contrastRange;
    QPair<int, int> m_hueRange;
    QPair<int, int> m_saturationRange;

    bool findPort();
    void querySupportedFormats();

    int getAttribute(const char *attribute, int minimum, int maximum) const;
    void setAttribute(const char *attribute, int value, int minimum, int maximum);

    static int redistribute(int value, int fromLower, int fromUpper, int toLower, int toUpper);
};

QT_END_NAMESPACE

#endif
