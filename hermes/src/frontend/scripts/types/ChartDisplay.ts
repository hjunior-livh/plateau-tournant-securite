export interface ChartDisplay {
    readonly id: string,
    HTMLElementId: string,
    canvas: HTMLCanvasElement | null,
    _ctx: ChartItem,
    _data: EventDataset,
    _chart?: Chart,
    xhr: XMLHttpRequest,
    render: ChartRenderer
} & (
    {
        readonly dataTable: string,
        defaultDataQuantity: number,
    }
)
