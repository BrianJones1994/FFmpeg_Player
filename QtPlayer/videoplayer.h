#pragma once

#include "ffmpegdecoder.h"


class VideoPlayer
{
public:
	enum VideoState
	{
		InitialState,
		Playing,
		Paused,
	};

	VideoPlayer();
	virtual ~VideoPlayer();

    FFmpegDecoderWrapper* getDecoder();
	VideoDisplay* getCurrentDisplay();
	virtual void setDisplay(VideoDisplay* display);
	VideoState state() const { return m_state; }

protected:
	void setState(VideoState newState);

private:
    FFmpegDecoderWrapper m_decoder;
	VideoDisplay* m_display{nullptr};
	VideoState m_state{InitialState};
};
