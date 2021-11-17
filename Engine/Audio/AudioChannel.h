#pragma once
#include<fmod.hpp>

namespace jc
{
	class AudioChannel
	{
	public:
		AudioChannel() {}
		AudioChannel(FMOD::Channel* channel) : channel{channel} {}

		void Stop();
		bool Isplaying();

		void SetPitch(float pitch);
		float GetPitch();

		void SetVolume(float volume);
		float getVolume();

	private:
		FMOD::Channel* channel{ nullptr };

	};
}