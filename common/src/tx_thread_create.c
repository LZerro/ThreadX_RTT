#define TX_SOURCE_CODE

#include "tx_api.h"

UINT _tx_thread_create(TX_THREAD *thread_ptr, CHAR *name_ptr, VOID (*entry_function)(ULONG id), ULONG entry_input,
                       VOID *stack_start, ULONG stack_size, UINT priority, UINT preempt_threshold,
                       ULONG time_slice, UINT auto_start)
{
    RT_ASSERT(thread_ptr);

    rt_thread_t Thread_temp_ptr = (rt_thread_t)thread_ptr;
    // 使用rt_thread_init后初始化堆栈的值为'#'
    rt_thread_init(Thread_temp_ptr, name_ptr, (thread_entry_func)entry_function, (void *)entry_input, stack_start, stack_size, priority, time_slice);

    if (auto_start == TX_AUTO_START)
    {
        rt_thread_startup(Thread_temp_ptr);
    }

    return TX_SUCCESS;
}
