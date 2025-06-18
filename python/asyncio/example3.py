import asyncio
import time


async def say_hello(name: str, delay: float):
    await asyncio.sleep(delay)
    print(f'Hello, {name}!')


async def main():
    # Use asyncio.TaskGroup to run coroutines concurrently as asyncio tasks.
    # Python 3.11+ only.
    async with asyncio.TaskGroup() as group:
        group.create_task(say_hello("Alice", 1.0))
        group.create_task(say_hello("Bob", 2.0))
        start = time.perf_counter()

    # The await is implicit when the context manager exits.
    end = time.perf_counter()
    print(f"{end - start:.2f} seconds have elapsed.")

if __name__ == "__main__":
    # Use asyncio.run() to run the coroutine.
    asyncio.run(main())
