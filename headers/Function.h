#ifndef FUNCTION_H
#define FUNCTION_H

#include "nodes/Node.h"
#include <QGraphicsScene>
#include <QListWidgetItem>
class Function: public QListWidgetItem{
public:
	struct InputNode: public Node{
		InputNode(uint rank);
		const uint _rank;
		data_t kernel()const;
		void paint(QPainter *, const QStyleOptionGraphicsItem *, QWidget *);
	};
	struct OutputNode: Node{
		OutputNode();
		inline data_t kernel()const{return iNodes[0]->eval();}
		void paint(QPainter *, const QStyleOptionGraphicsItem *, QWidget *);
	};
	Function();
	~Function();
	uint nbArgs;
	OutputNode* start;
	QVector<InputNode*> iNodes;
	QGraphicsScene* scene;
public slots:
	void changeNbArgs(uint args);
};

#endif // FUNCTION_H