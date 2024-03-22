using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using TMPro;
using System.IO.Ports;

internal enum TaskState {
    Init,
    WaitStart,
    WaitEvents
}


public class EjercicioFinalUnidad2 : MonoBehaviour 
{
    private static TaskState _taskState = TaskState.Init;
    private SerialPort _serialPort;
    private byte[] _buffer;
    public TextMeshProUGUI myText;
    private int _counter;
    private bool _isSendingData = false;

    private void Start() 
    {
        _serialPort = new SerialPort();
        _serialPort.PortName = "COM8";
        _serialPort.BaudRate = 115200;
        _serialPort.DtrEnable = true;
        _serialPort.Open();
        Debug.Log("Open Serial Port");
        _buffer = new byte[128];

    }

    private IEnumerator SendData() 
    {
        while (_isSendingData) 
        {
            var randomNumber = Random.Range(0, 300);
            byte[] data = { (byte)randomNumber };
            _serialPort.Write(data, 0, 1);
            myText.text = randomNumber.ToString();
            yield return new WaitForSeconds(3);
        }
    }

    private void Update()
    {

        switch (_taskState)
        {
            case TaskState.Init:
                _taskState = TaskState.WaitStart;
                Debug.Log("WAIT START");
                break;
            case TaskState.WaitStart:
                if (Input.GetKeyDown(KeyCode.A))
                {
                    byte[] data = { 0x31 }; // start
                    _serialPort.Write(data, 0, 1);
                    Debug.Log("WAIT EVENTS");
                    _taskState = TaskState.WaitEvents;
                }

                break;
            case TaskState.WaitEvents:
                if (Input.GetKeyDown(KeyCode.B))
                {
                    byte[] data = { 0x32 }; // stop
                    _serialPort.Write(data, 0, 1);
                    Debug.Log("WAIT START");
                    _taskState = TaskState.WaitStart;
                }

                if (_serialPort.BytesToRead > 0)
                {
                    var numData = _serialPort.Read(_buffer, 0, 128);
                    Debug.Log(System.Text.Encoding.ASCII.GetString(_buffer));
                }

                if (Input.GetKeyDown(KeyCode.K))
                {
                    _isSendingData = !_isSendingData;
                    StartCoroutine(SendData());
                }

                if (Input.GetKeyDown(KeyCode.S))
                {
                    _isSendingData = false;
                }
                break;
            default:
                Debug.Log("State Error");
                break;
        }
    }
}