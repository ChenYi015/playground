import asyncio
import time


async def say_hello(name: str, delay: float):
    await asyncio.sleep(delay)
    print(f'Hello, {name}!')


async def main():
    start = time.perf_counter()
    await say_hello("Alice", 1.0)
    await say_hello("Bob", 2.0)
    end = time.perf_counter()
    print(f"{end - start:.2f} seconds have elapsed.")

if __name__ == "__main__":
    # Use asyncio.run() to run the coroutine.
    asyncio.run(main())
