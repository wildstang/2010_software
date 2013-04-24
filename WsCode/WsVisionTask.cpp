
#include <stdio.h>
#include <semLib.h>

#include "WsVisionTask.h"
#include "WsCamera.h"
#include "Timer.h"

SEM_ID g_visionSemaphore;
SharedVisionDataT g_visionData;
int g_visionTaskPrintEnable = 0;


int vision_task_main()
{
  bool keepGoing = true;
  int idx = 0;
  WsVisionTarget target;
  VisionDataT *candidate = NULL;


  // The silly camera has to boot up, give it some time
  Wait(3.0);
  printf("before axis cam\n");
  AxisCamera &axisCam = AxisCamera::GetInstance();
  printf("after axis cam\n");
  WsCamera camera = WsCamera(&axisCam);
  printf("after axis cam\n");

  /* loop fooooooorrrrrrreeeeeevvvvvveeeeerrrrrrr */
  while (keepGoing == true)
  {
      Wait(1.0);
      continue;
    /* This is a blocking call that waits for a new image to be processed */
    camera.findCandidates();

    /* got camera data, write it to shared memory */
    semTake(g_visionSemaphore, WAIT_FOREVER);

    g_visionData.foundTarget = camera.isTargetFound();
    g_visionData.targetHeading = camera.getTargetHeading();
    g_visionData.numCandidates = camera.getNumCandidates();

    if (g_visionData.numCandidates > MAX_NUM_CANDIDATES)
    {
      g_visionData.numCandidates = MAX_NUM_CANDIDATES;
    }

    for (idx = 0; idx < g_visionData.numCandidates; idx++)
    {
      candidate = &g_visionData.candidateData[idx];

      if (camera.getCandidateInfo(idx, target) == true)
      {
        candidate->valid = true;

        candidate->majorRadius = target.a_majorRadius;
        candidate->minorRadius = target.a_minorRadius;
        candidate->rawScore = target.a_rawScore;
        candidate->xPos = target.a_xPos;
        candidate->yPos = target.a_yPos;
        candidate->score = target.a_score;
        candidate->rotation = target.a_rotation;
        candidate->xMax = target.a_xMax;
        candidate->bothFound = target.a_bothFound;
      }
      else
      {
        candidate->valid = false;
      }
    }

    semGive(g_visionSemaphore);
  }

  return 0;
}

