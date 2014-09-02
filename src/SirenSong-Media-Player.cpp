#ifdef QT_QML_DEBUG
#include <QtQuick>
#endif

#include <sailfishapp.h>
#include "mediaplayer.h"
#include "playlistmodel.h"

static QObject *player(QQmlEngine *engine, QJSEngine *scriptEngine)
{
    Q_UNUSED(engine);
    Q_UNUSED(scriptEngine);
    static MediaPlayer *player = NULL;
    if (!player) {
        player = new MediaPlayer();
    }
    return player;
}

int main(int argc, char *argv[])
{
    //qmlRegisterType <MediaPlayer> ( "com.wayfarer.sirensong", 1, 0, "MediaPlayer" );

    qmlRegisterSingletonType<MediaPlayer>("com.wayfarer.sirensong", 1, 0, "SirenSong", player);

    qmlRegisterType<PlaylistModel>("com.wayfarer.sirensong", 1, 0, "PlaylistModel");

    // SailfishApp::main() will display "qml/template.qml", if you need more
    // control over initialization, you can use:
    //
    //   - SailfishApp::application(int, char *[]) to get the QGuiApplication *
    //   - SailfishApp::createView() to get a new QQuickView * instance
    //   - SailfishApp::pathTo(QString) to get a QUrl to a resource file
    //
    // To display the view, call "show()" (will show fullscreen on device).

    return SailfishApp::main(argc, argv);
}

