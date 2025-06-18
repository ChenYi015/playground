import aiohttp
from aiohttp import web


async def handle(request: web.Request) -> web.Response:
    name = request.match_info.get('name', "World")
    text = f"Hello, {name}!"
    return web.Response(text=text)


class Server:

    def __init__(self, host: str, port: int):
        self._host = host
        self._port = port

        app = web.Application()
        app.add_routes([
            web.get('/', handle),
            web.get('/{name}', handle)
        ])
        self._app = app

    def run(self):
        print("Server started...")
        web.run_app(self._app, host=self._host, port=self._port)
        print("Server closed...")


if __name__ == '__main__':
    server = Server('127.0.0.1', 8080)
    server.run()
