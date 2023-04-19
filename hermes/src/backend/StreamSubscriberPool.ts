import { Response } from 'express'


const headers = {
    'Content-Type': 'text/event-stream',    // Permet d'indiquer au client qu'il s'agit d'une connexion SSE 
    'Connection': 'keep-alive',             // Permet d'indiquer au client que la connexion est persistente
    'Cache-Control': 'no-cache'             // Permet d'empêcher la mise en cache des messages
};


interface Subscriber {
    id: number,
    res: Response
    
}


export class StreamSubscriberPool {
    private subscribers: Subscriber[];

    constructor() {
        this.subscribers = [];
    }

    public addSubscriber(responseObj: Response) : Subscriber {
        const subscribersId = Date.now();
        const newSubscriber = {
            id: subscribersId,
            res: responseObj
        };
        this.subscribers.push(newSubscriber)

        newSubscriber.res.on('close', () => {
            console.log(`${newSubscriber.id}: Connection closed`);
            this.subscribers = this.subscribers.filter((client: Subscriber) => client.id !== subscribersId);
        });

        return newSubscriber;
    }

    public sendEvent(eventType: string, data: Object) : void {
        var subscriber: Subscriber;
        for (let i = 0; i < this.subscribers.length; i++) {
            subscriber = this.subscribers[i];

            subscriber.res.writeHead(200, headers);

            const id = new Date().toISOString();
            let msg: string = `event:${eventType}\ndata:${JSON.stringify(data)}\nid:${id}\n\n`;
            console.log(`Stream event : ${msg}`);
            subscriber.res.write(msg);
        }
    }
}