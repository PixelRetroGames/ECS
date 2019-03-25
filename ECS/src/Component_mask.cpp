#include "../include/Component_mask.h"

namespace ECS
{
    bool Component_mask::Is_matching(Component_mask system_mask)
    {
     return (system_mask.mask-(system_mask.mask&mask))==0;
     //return mask==system_mask.mask;
    }

    bool Component_mask::Is_new_match(Component_mask old_mask,Component_mask system_mask)
    {
     return (Is_matching(system_mask) && !old_mask.Is_matching(system_mask));
    }

    bool Component_mask::Is_no_longer_matching(Component_mask old_mask,Component_mask system_mask)
    {
     return (old_mask.Is_matching(system_mask) && !Is_matching(system_mask));
    }
}
