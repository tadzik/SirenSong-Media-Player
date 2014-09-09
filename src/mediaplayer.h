#ifndef MEDIAPLAYER_H
#define MEDIAPLAYER_H

#include <QtMultimedia>
#include "trackerinterface.h"
#include "playlistmodel.h"

class MediaPlayer : public QObject
{
    Q_OBJECT
    Q_PROPERTY ( int playbackStatus READ playbackStatus NOTIFY playbackStatusChanged )
    Q_PROPERTY ( qint64 position READ position NOTIFY positionChanged )
    Q_PROPERTY ( qint64 duration READ duration NOTIFY durationChanged )
    Q_PROPERTY(QString title READ title NOTIFY titleChanged)
    Q_PROPERTY(QString artist READ artist NOTIFY artistChanged)
    Q_PROPERTY(int currentIndex READ currentIndex NOTIFY currentIndexChanged)
    Q_PROPERTY(PlaylistModel * playlistModel READ playlistModel)

public:
    MediaPlayer(QObject * parent = 0 );
    const int &playbackStatus( );
    const qint64 &position( );
    const qint64 &duration( );
    const QString &title( );
    const QString &artist( );
    const int &currentIndex( );
    PlaylistModel* &playlistModel();


public slots:
    void play( );
    void play(QString url);
    void playIndex(int index);
    void next( );
    void previous( );
    void pause( );
    void stop( );
    void addToPlaylist(QString url);
    //void setCurrentResultsQuery(QString query);


signals:
    void playbackStatusChanged( );
    void positionChanged( );
    void durationChanged( );
    void titleChanged( );
    void artistChanged( );
    void currentIndexChanged();

private:
    QMediaPlayer * player;
    QMediaPlaylist * playlist;
    int iPlaybackStatus;
    qint64 iPosition;
    qint64 iDuration;
    QString sCurrentResultsQuery;
    QSparqlResult * result;
    trackerinterface * tracker;
    QString mediaTitle;
    QString mediaArtist;
    int iCurrentIndex;
    PlaylistModel * plModel;

private slots:
    void setPlaybackStatus( QMediaPlayer::State state );
    void setPosition(qint64 position);
    void setDuration(qint64 duration);
    void setTitle(QString title);
    void setArtist(QString artist);
    void checkPlaylist(int currentIndex);
    void randomItemComplete(QString url);
    void metaDataCallback(const QString &key, const QVariant &value);
};

#endif // MEDIAPLAYER_H
