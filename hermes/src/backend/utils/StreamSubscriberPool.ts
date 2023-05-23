import { Response } from 'express'


// SSE stream subscriber
type Subscriber = {
    id: number,
    res: Response,
}

// Response's headers for SSE event message
const headers = {
    'Content-Type': 'text/event-stream',
    'Connection': 'keep-alive',
    'Cache-Control': 'no-cache'
}


// Stream Subscriber Pool
export class StreamSubscriberPool {

    private subscribers: Subscriber[];
    private subIdCounter: number;

    constructor() {
        this.subscribers = [];
        this.subIdCounter = 0;
    }

    public addSubscriber(res: Response): Subscriber {
        const subscribersId = this.subIdCounter++;
        const newSubscriber = {
            id: subscribersId,
            res: res
        };
        this.subscribers.push(newSubscriber);
        console.log(`[+] New data stream subscriber: ID=${subscribersId.toString().padStart(3, "0")}`);

        newSubscriber.res.on("close", () => {
            console.log(`[-] Closing of a data stream subscriber: ID=${newSubscriber.id.toString().padStart(3, "0")}`);
            this.subscribers = this.subscribers.filter((client: Subscriber) => client.id !== subscribersId);
        });

        return newSubscriber;
    }

    public sendEvent(eventType: string, dataTable: string, dataEntry: Object): void {
        for (const subscriber of this.subscribers) {
            if (!subscriber.res.headersSent) {
                subscriber.res.writeHead(200, headers);
            }
            const id = new Date().toISOString();
            const message: unknown = {"table": dataTable, "entry": dataEntry};
            let msg: string = `event:${eventType}\ndata:${JSON.stringify(message)}\nid:${id}\n\n`;
            subscriber.res.write(msg);
        }
    }
}