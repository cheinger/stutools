#ifndef _AIOREADS_H
#define _AIOREADS_H

#include <libaio.h>

#include "logSpeed.h"
#include "positions.h"

size_t aioMultiplePositions( positionType *positions,
			     const size_t sz,
			     const float secTimeout,
			     const size_t QD,
			     const int verbose,
			     const int tableMode,
			     logSpeedType *alll,
			     logSpeedType *benchl,
			     char *randomBuffer,
			     const size_t randomBufferSize,
			    const size_t alignment,
			    size_t *ios,
			    size_t *totalRB,
			     size_t *totalWB,
			     const size_t oneShot,
			     int dontExitOnErrors,
			     io_context_t *ioc,
			     size_t contextCount);

int aioVerifyWrites(positionType *positions,
		    const size_t maxpos,
		    const size_t maxBufferSize,
		    const size_t alignment,
		    const int verbose,
		    const char *randomBuffer);

void aioSetup(io_context_t *ctx, size_t QD);
struct iocb * aioGetContext();
int aioRead(io_context_t *ctx, struct iocb *cbs, int fd, void* data, size_t len, size_t pos);


int aioGet(io_context_t *ctx);


#endif
