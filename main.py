from fastapi import FastAPI, WebSocket, WebSocketDisconnect
import json

app = FastAPI()

@app.get("/")
def health_check():
    return {"status": "Xiaozhi backend is running"}

@app.websocket("/ws")
async def websocket_endpoint(websocket: WebSocket):
    await websocket.accept()
    print("[Server] ESP32 Client Connected via WebSocket")
    
    try:
        while True:
            message = await websocket.receive()
            
            if "text" in message:
                data = message["text"]
                print(f"[Server Received Text]: {data}")
                
                try:
                    payload = json.loads(data)
                    msg_type = payload.get("type")
                    
                    if msg_type == "hello":
                        response = {
                            "type": "hello",
                            "version": 1,
                            "transport": "websocket"
                        }
                        await websocket.send_text(json.dumps(response))
                        
                    elif msg_type == "mcp_event":
                        ack = {
                            "type": "tts",
                            "text": "MCP tool command acknowledged by server!"
                        }
                        await websocket.send_text(json.dumps(ack))
                        
                except json.JSONDecodeError:
                    pass
                    
            elif "bytes" in message:
                audio_chunk = message["bytes"]
                print(f"[Server Received Audio Chunk]: {len(audio_chunk)} bytes")
                
                simulated_reply = {
                    "type": "tts",
                    "text": "Received your voice snippet!"
                }
                await websocket.send_text(json.dumps(simulated_reply))
                
    except WebSocketDisconnect:
        print("[Server] ESP32 Client Disconnected")
