#include "view.h"

double hit_world(t_scene scene) {
	return 0.0;
}

double hit_cylinder(t_cylinder cylinder, t_ray ray)
{
	double t;
	t = positive_min_2(hit_cylinder_cap(cylinder, ray, cylinder.bottom),
		hit_cylinder_cap(cylinder, ray, cylinder.top));
	return positive_min_2(hit_cylinder_side(cylinder, ray), t);
}

double hit_cylinder_side(t_cylinder cylinder, t_ray ray) {
	t_vector co;
	t_vector vector; 
	double a;
	double b;
	double c;

	co = minus_vector(ray.origin, cylinder.center);
	a = inner_product(cross_product(ray.dv, cylinder.dv), cross_product(ray.dv, cylinder.dv));
	b = 2 * inner_product(cross_product(ray.dv, cylinder.dv), cross_product(co, cylinder.dv));
	c = inner_product(cross_product(co, cylinder.dv), cross_product(co, cylinder.dv))
		- cylinder.radius * cylinder.radius;
	double t = positive_min_root_two_degree(a, b, c);
	if (t < 0)
		return (-1.0);
	vector = ray_at(&ray, t);
	if (fabs(inner_product(minus_vector(vector, cylinder.center), cylinder.dv)) <= cylinder.height / 2 ) {
		return (t);
	} 
	return (-1.0);
}

double hit_cylinder_cap(t_cylinder cylinder, t_ray ray, t_vector cap_center) {
	double b;
	double c;
	t_vector co;
	t_vector vector;

	co = minus_vector(ray.origin, cap_center);
	b = inner_product(ray.dv , cylinder.dv);
	c = - inner_product(co, cylinder.dv);
	if (c / b < 0)
		return (-1.0);
	vector = ray_at(&ray, c / b);	
	if (inner_product(minus_vector(vector, cap_center) , 
		minus_vector(vector, cap_center)) <= cylinder.radius * cylinder.radius)
		return c / b;
	return -1.0;
}

double hit_sphere(t_sphere sphere, t_ray ray)
{
	t_vector co = minus_vector(ray.origin, sphere.center);
	double a = inner_product(ray.dv, ray.dv);
	double b = 2.0 * inner_product(co, ray.dv);
	double c = inner_product(co, co) - sphere.radius * sphere.radius;
	return positive_min_root_two_degree(a, b, c);
}

double hit_plane(t_plane plane, t_ray ray) {
	double b;
	double c;
	t_vector po; 

	po = minus_vector(ray.origin, plane.point);
	b = inner_product(ray.dv , plane.dv);
	c = - inner_product(po, plane.dv);
	return positive_min_root_one_degree(b, c);
}