// Code source : https://www.codeheroes.fr/2020/06/02/communication-temps-reel-avec-server-sent-events-sse/

import { Response } from 'express'


export function sendSSEMessage(res: Response, event: any, data: Object) { // TODO: Ajouter champs 'retry' (?)
    const headers = {
        /* Permet d'indiquer au client qu'il s'agit d'une connexion SSE */
        'Content-Type': 'text/event-stream',
        /* Permet d'indiquer au client que la connexion est persistente */
        Connection: 'keep-alive',
        /* Permet d'empêcher la mise en cache des messages */
        'Cache-Control': 'no-cache'
    };
    res.writeHead(200, headers);

    const id = new Date().toISOString();
    const msgContent: string = `event:${event}\ndata:${data}\nid:${id}\n\n`;
    res.write(JSON.stringify(msgContent));
}