# Public Headers

Public API headers are stored in `include/ls/`.

Applications should include the common module API first when they need module
identity, memory, temperature or safe service initialization:

```c
#include "ls/ls_api.h"
```

Lower-level headers remain available when a product needs direct access:

```c
#include "ls/ls_mcp3208.h"
#include "ls/ls_bms.h"
#include "ls/ls_io.h"
```
