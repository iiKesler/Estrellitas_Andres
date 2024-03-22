using System.IO.Ports;
using TMPro;
using UnityEngine;

namespace Ejercicio_4
{
    internal enum TaskState
    {
        Init,
        WaitCommands
    }

    public class Serial5 : MonoBehaviour
    { private static TaskState _taskState = TaskState.Init;
        private SerialPort _serialPort;
        private byte[] _buffer;
        public TextMeshProUGUI myText;
        private int _counter = 0;

        private void Start()
        {
            _serialPort =new SerialPort();
            _serialPort.PortName = "COM3";
            _serialPort.BaudRate = 115200;
            _serialPort.DtrEnable =true;
            _serialPort.NewLine = "\n";
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
                    _taskState = TaskState.WaitCommands;
                    Debug.Log("WAIT COMMANDS");
                    break;
                case TaskState.WaitCommands:
                    if (Input.GetKeyDown(KeyCode.A))
                    {
                        _serialPort.Write("ledON\n");
                        Debug.Log("Send ledON");
                    }
                    if (Input.GetKeyDown(KeyCode.S))
                    {
                        _serialPort.Write("ledOFF\n");
                        Debug.Log("Send ledOFF");
                    }
                    if (Input.GetKeyDown(KeyCode.R))
                    {
                        _serialPort.Write("readBUTTONS\n");
                        Debug.Log("Send readBUTTONS");
                    }
                    if (_serialPort.BytesToRead > 0)
                    {
                        string response = _serialPort.ReadLine();
                        Debug.Log(response);
                    }
                    break;
                default:
                    Debug.Log("State Error");
                    break;
            }
        }
    }
}