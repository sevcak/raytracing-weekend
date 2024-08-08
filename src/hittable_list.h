#ifndef HITTABLE_LIST_H
#define HITTABLE_LIST_H

#include "hittable.h"

#include <memory>
#include <vector>

using std::make_shared;
using std::shared_ptr;

class hittable_list : public hittable
{
public:
    std::vector<shared_ptr<hittable>> objects;

    hittable_list() {}
    hittable_list( shared_ptr<hittable> object ) { add( object ); }

    void clear() { objects.clear(); }

    void add( shared_ptr<hittable> object )
    {
        objects.push_back( object );
    }

    bool hit( const ray& r, interval ray_t, hit_record& rec ) const override
    {
        hit_record temp_rec;
        bool       hit_something = false;
        auto       closest       = ray_t.max;

        for ( const auto& object : objects ) {
            if ( object->hit( r, interval( ray_t.min, closest ), temp_rec ) ) {
                hit_something = true;
                closest = temp_rec.t;
                rec = temp_rec;
            }
        }

        return hit_something;
    }
};

#endif
