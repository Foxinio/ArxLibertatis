
#ifndef ARX_AUDIO_DSOUND_DSOUNDBACKEND_H
#define ARX_AUDIO_DSOUND_DSOUNDBACKEND_H

#include "audio/dsound/dsoundfwd.h"

#include "audio/AudioBackend.h"
#include "audio/AudioTypes.h"
#include "audio/AudioResource.h"

namespace audio {

class DSoundSource;

class DSoundBackend : public Backend {
	
public:
	
	DSoundBackend();
	~DSoundBackend();
	
	aalError init(bool enableEax);
	
	aalError updateDeferred();
	
	Source * createSource(aalSLong sampleId, const aalChannel & channel);
	
	Source * getSource(aalSLong sourceId);
	
	aalError setReverbEnabled(bool enable);
	
	aalError setUnitFactor(float factor);
	aalError setRolloffFactor(float factor);
	
	aalError setListenerPosition(const aalVector & position);
	aalError setListenerOrientation(const aalVector & front, const aalVector & up);
	
	aalError setListenerEnvironment(const Environment & env);
	aalError setRoomRolloffFactor(float factor);
	
	source_iterator sourcesBegin();
	source_iterator sourcesEnd();
	source_iterator deleteSource(source_iterator it);
	
private:
	
	LPDIRECTSOUND device;
	LPDIRECTSOUNDBUFFER primary;
	LPDIRECTSOUND3DLISTENER listener;
	LPKSPROPERTYSET environment;
	
	ResourceList<DSoundSource> sources;
	
	bool hasEAX;
	
	friend class DSoundSource;
};

} // namespace audio

#endif // ARX_AUDIO_DSOUND_DSOUNDBACKEND_H
