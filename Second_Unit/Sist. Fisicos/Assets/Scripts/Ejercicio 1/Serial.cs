using System.IO.Ports;
using UnityEngine;

namespace Ejercicio_1
{
    public class Serial : MonoBehaviour {
        private readonly SerialPort _serialPort =new SerialPort();
        private readonly byte[] _buffer =new byte[32];

        private void Start() {
            _serialPort.PortName = "COM8";
            _serialPort.BaudRate = 115200;
            _serialPort.DtrEnable =true;
            _serialPort.Open();
            Debug.Log("Open Serial Port");
        }

        private void Update(){ 
            if (Input.GetKeyDown(KeyCode.A)) {
                byte[] data = {0x31};// or byte[] data = {'1'};
                _serialPort.Write(data,0,1);
                Debug.Log("Send Data");
            }

            if (Input.GetKeyDown(KeyCode.B)) {
                if (_serialPort.BytesToRead >= 16) {
                    _serialPort.Read(_buffer, 0, 20);
                    Debug.Log("Receive Data");
                    Debug.Log(System.Text.Encoding.ASCII.GetString(_buffer));
                }
            }
        }
    }
}
