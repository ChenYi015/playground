import asyncio
import aiohttp


class Client:
    def __init__(self, base_url: str):
        self._base_url = base_url

    async def get_data(self, url: str) -> dict:
        async with aiohttp.ClientSession(self._base_url) as session:
            async with session.get(url) as response:
                text = await response.text()
                result = {
                    "Status": response.status,
                    "Content-type": response.headers["content-type"],
                    "text": text,
                }
        return result


async def main():
    client = Client("http://127.0.0.1:8080")
    tasks = [asyncio.create_task(client.get_data(path))
             for path in ["/", "/Alice", "/Bob"]]
    results = [await task for task in tasks]
    for result in results:
        print(result)


if __name__ == "__main__":
    asyncio.run(main())
