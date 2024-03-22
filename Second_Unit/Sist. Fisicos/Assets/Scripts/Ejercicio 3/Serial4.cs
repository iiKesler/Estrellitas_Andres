using System.IO.Ports;
using TMPro;
using UnityEngine;

namespace Ejercicio_3
{
    internal enum TaskState
    {
        Init,
        WaitStart,
        WaitEvents
    }

    public class Serial4 : MonoBehaviour
    {
        private static TaskState _taskState = TaskState.Init;
        private SerialPort _serialPort;
        private byte[] _buffer;
        public TextMeshProUGUI myText;
        private int _counter;

        private void Start()
        {
            _serialPort =new SerialPort();
            _serialPort.PortName = "COM3";
            _serialPort.BaudRate = 115200;
            _serialPort.DtrEnable =true;
            _serialPort.Open();
            Debug.Log("Open Serial Port");
            _buffer =new byte[128];
        }

        private void Update()
        {
            myText.text = _counter.ToString();
            _counter++;

            switch (_taskState)
            {
                case TaskState.Init:
                    _taskState = TaskState.WaitStart;
                    Debug.Log("WAIT START");
                    break;
                case TaskState.WaitStart:
                    if (Input.GetKeyDown(KeyCode.A))
                    {
                        byte[] data = {0x31};// start
                        _serialPort.Write(data,0,1);
                        Debug.Log("WAIT EVENTS");
                        _taskState = TaskState.WaitEvents;
                    }
                    break;
                case TaskState.WaitEvents:
                    if (Input.GetKeyDown(KeyCode.B))
                    {
                        byte[] data = {0x32};// stop
                        _serialPort.Write(data,0,1);
                        Debug.Log("WAIT START");
                        _taskState = TaskState.WaitStart;
                    }
                    if (_serialPort.BytesToRead > 0)
                    {
                        var numData = _serialPort.Read(_buffer, 0, 128);
                        Debug.Log(System.Text.Encoding.ASCII.GetString(_buffer));
                    }
                    break;
                default:
                    Debug.Log("State Error");
                    break;
            }
        }
    }
}