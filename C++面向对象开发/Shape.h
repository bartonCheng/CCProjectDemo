#pragma once //ϵͳ�趨�ķ�ֹ�ظ�������
#ifndef SHAPE_H 
//���δ���� �Ŷ������
/*
* ˵�� �� shape�������״������
* 1. Protected ���εı����ͷ��������Ա�����ͼ̳е���������ʡ�
* 2. Private ���εı����ͷ�������������Է��ʡ���ΪȨ�����Ρ�
* 3. Public ���εı����ͷ��������ڹ����ķ��ʣ���Ȩ�����ơ�
*/

class Shape
{
protected: //����������������
	double shape_width{ 0 };
	double shape_length{ 0 };
	double shape_height{ 0 };
	double height{ 0 }; //�߶�
	double width{ 0 }; //���
public:
	//����Ĺ��췽��
	//Shape() = delete;
	//�������������
	//~Shape();
	//��ʽ��ʼ�����캯��
	Shape(int i) : shape_width(i), shape_length(i), shape_height(i) {}

	double Volume(int i);

private:

};



#endif // !SHAPE_H 

