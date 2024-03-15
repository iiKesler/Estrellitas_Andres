using UnityEngine;
using System.IO.Ports;
using TMPro;

public class Serial2 : MonoBehaviour {
	private readonly SerialPort _serialPort = new SerialPort();
	private readonly byte[] _buffer = new byte[32];
	public TextMeshProUGUI myText;

	private static int _counter = 0;

	private void Start() {
		_serialPort.PortName = "COM8";
		_serialPort.BaudRate = 115200;
		_serialPort.DtrEnable = true;
		_serialPort.Open();
		Debug.Log("Open Serial Port");
	}

	private void Update() { 
		myText.text = _counter.ToString();
		_counter++;
		
		if (Input.GetKeyDown(KeyCode.A)) {
			byte[] data = { 0x31 }; // or byte[] data = {'1'};            
			_serialPort.Write(data, 0, 1);
			var numData = _serialPort.Read(_buffer, 0, 20);
			Debug.Log(System.Text.Encoding.ASCII.GetString(_buffer));
			Debug.Log("Bytes received: " + numData.ToString()); 
		}
	}
}
