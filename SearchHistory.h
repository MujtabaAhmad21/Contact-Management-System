#pragma once
#include <iostream>
#include "HistoryObject.h"
#include <unordered_map>
#include <iostream>
#include <iomanip>

class SearchHistory {
private:
	struct Node {
		HistoryObject data;
		Node* next;
		Node(const HistoryObject& d) : data(d), next(nullptr) {}
	};

	Node* historyListHead;
	int size;

	// Helper function to sort the linked list in descending order of search time
	void SortLinkedList() {
		if (size <= 1) return;

		Node* current = historyListHead;
		while (current->next != nullptr) {
			Node* innerCurrent = historyListHead;
			while (innerCurrent->next != nullptr) {
				if (innerCurrent->data.G_Search_Time() < innerCurrent->next->data.G_Search_Time()) {
					// Swap data
					HistoryObject temp = innerCurrent->data;
					innerCurrent->data = innerCurrent->next->data;
					innerCurrent->next->data = temp;
				}
				innerCurrent = innerCurrent->next;
			}
			current = current->next;
		}
	}

public:
	SearchHistory() : historyListHead(nullptr), size(0) {}

	void search(const std::string& searchStr) {
		HistoryObject newHistory(searchStr);
		Node* newNode = new Node(newHistory);
		newNode->next = historyListHead;
		historyListHead = newNode;
		size++;
	}

	void Display_History() {
		std::cout << "Search History (Latest First):" << std::endl;

		SortLinkedList(); // Sort the linked list

		Node* current = historyListHead;
		while (current != nullptr) {
			time_t searchTime = current->data.G_Search_Time();
			tm localTime;
			localtime_s(&localTime, &searchTime); // Corrected argument
			std::cout << current->data.G_Search_String() << " ("
				<< std::put_time(&localTime, "%Y-%m-%d %H:%M:%S") << ")" << std::endl;
			current = current->next;
		}
	}

	void Display_Top5_Contacts() {
		std::unordered_map<std::string, int> searchCountMap;

		Node* current = historyListHead;
		while (current != nullptr) {
			searchCountMap[current->data.G_Search_String()]++;
			current = current->next;
		}

		std::vector<std::pair<std::string, int>> sortedSearchCountVec;
		for (const auto& entry : searchCountMap) {
			sortedSearchCountVec.push_back(entry);
		}

		// Manual sort to find the top 5 frequently searched contacts
		for (size_t i = 0; i < sortedSearchCountVec.size() - 1; ++i) {
			for (size_t j = i + 1; j < sortedSearchCountVec.size(); ++j) {
				if (sortedSearchCountVec[i].second < sortedSearchCountVec[j].second) {
					std::swap(sortedSearchCountVec[i], sortedSearchCountVec[j]);
				}
			}
		}

		std::cout << "Top 5 Frequently Searched Contacts:" << std::endl;
		int count = 0;
		for (const auto& entry : sortedSearchCountVec) {
			std::cout << std::setw(15) << std::left << entry.first << " : " << entry.second << " times" << std::endl;
			count++;
			if (count >= 5) {
				break;
			}
		}
	}

	~SearchHistory() {
		while (historyListHead != nullptr) {
			Node* temp = historyListHead;
			historyListHead = historyListHead->next;
			delete temp;
		}
	}
};
