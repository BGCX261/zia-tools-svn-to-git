#ifndef _ZIA_API_DATATREE_H_
#define _ZIA_API_DATATREE_H_

#include <map>
#include <string>
#include <iostream>
#include <list>

#include "defines.hpp"

namespace zia{
	namespace api{
		class DataTree
		{
		public:
			std::map<std::string, DataTree>     mSubs;
			std::string                         mValue;
			std::list<std::string>              mList;
			DataTree();
			virtual ~DataTree();
			operator const std::string& () const;
			DataTree&               operator = (const DataTree& dataTree);
			DataTree&               operator = (const std::string& value);
			DataTree&               operator += (const DataTree& dataTree);
			const DataTree&         operator [] (const std::string& key) const;
			DataTree&               operator [] (const std::string& key);
			bool                    operator == (const std::string& right) const;
			bool                    operator != (const std::string& right) const;
			const DataTree&         c() const;
			const std::string&      v() const;
			bool                    has(const std::string& key) const;
			const DataTree&         get(const std::string& key) const;
			void                    clear();
			void                    print(std::ostream& out, int indentLevel = 0) const;
		};

	};
};
#endif /* _ZIA_API_DATATREE_H_ */
