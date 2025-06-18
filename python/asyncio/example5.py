import asyncio


async def task(task_id: int, delay: float):
    print(f'Task {task_id} started.')
    await asyncio.sleep(delay)
    print(f'Task {task_id} finished.')


async def task_with_exception(task_id: int, delay: float):
    print(f'Task {task_id} started.')
    await asyncio.sleep(delay)
    raise Exception(f'Task {task_id} failed.')


async def main():
    async with asyncio.TaskGroup() as group:
        for i in range(10):
            group.create_task(task(i, i))
        group.create_task(task_with_exception(11, 5.5))

if __name__ == '__main__':
    asyncio.run(main())
