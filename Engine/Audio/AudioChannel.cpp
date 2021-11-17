#include "Audio/AudioChannel.h"

namespace jc
{
	bool AudioChannel::Isplaying()
	{
		if (channel == nullptr) return false;
		bool isPlaying;
		channel->isPlaying(&isPlaying);

		return isPlaying;
	}

	void AudioChannel::SetPitch(float pitch)
	{
		if (Isplaying())
		{
			channel->setPitch(pitch);
		}
	}

	float AudioChannel::GetPitch()
	{
		float pitch =0;

		if (Isplaying())
		{
			channel->getPitch(&pitch);
		}
		return pitch;
	}

	void AudioChannel::SetVolume(float volume)
	{
		if (Isplaying())
		{
			channel->setPitch(volume);
		}
	}

	float AudioChannel::getVolume()
	{

		float volume = 0;

		if (Isplaying())
		{
			channel->getVolume(&volume);
		}
		return volume;
	}

	void AudioChannel::Stop()
	{
		if (Isplaying())
		{
			channel->stop();
		}
	}

}