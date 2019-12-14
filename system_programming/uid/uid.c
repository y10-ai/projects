/*********************************/
/*   			             	 */
/*   System Programming          */
/*   UID                         */
/*   Author: Yonatan Zaken       */
/*   Last Updated 11/12/19       */
/*   Reviewed by:                */   
/*			                   	 */
/*********************************/

#include <stdlib.h>

#include "uid.h"

struct Uid
{
    time_t time_stamp;
    size_t counter;
    pid_t pid;
};

ilrd_uid_t UIDCreate()
{
    ilrd_uid_t new_uid;
    static size_t counter = 0;
    
    new_uid.time_stamp = time(NULL);
    new_uid.pid = getpid();
    new_uid.counter = ++counter;
    
    return new_uid;
}

int UIDIsBad(ilrd_uid_t uid)
{
    if (0 == uid.time_stamp)
    {
        return 1;
    }
    
    return 0;
}

int UIDIsSame(ilrd_uid_t uid1, ilrd_uid_t uid2)
{
    if (uid1.time_stamp == uid1.time_stamp &&
        uid1.counter    == uid2.counter    &&
        uid1.pid        == uid2.pid)
    {
        return 1;       
    }
    
    return 0;   
}
