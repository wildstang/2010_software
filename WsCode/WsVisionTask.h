
#define MAX_NUM_CANDIDATES 20

typedef struct
{
  bool valid;
  double majorRadius;
  double minorRadius;
  double rawScore;
  double xPos;
  double yPos;
  double score;
  double rotation;
  double xMax;
  bool   bothFound;
} VisionDataT;

typedef struct
{
  bool        foundTarget;
  double      targetHeading;
  int         numCandidates;
  VisionDataT candidateData[MAX_NUM_CANDIDATES];
} SharedVisionDataT;

extern SEM_ID g_visionSemaphore;
extern SharedVisionDataT g_visionData;

extern int vision_task_main();

